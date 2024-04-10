#include <bits/stdc++.h>
using namespace std;

struct Solver
{
    int N;
    vector<int> A, B;
    vector<bool> m, z, p;
    vector<int> ms, zs, ps;
    static bool all(const vector<int>& V, int from, int to)
    {
        if(from > to) return true;
        // cout << from << " " << to << endl;
        int sv = V[to] - (from == 0 ? 0 : V[from-1]);
        return sv == to - (from - 1);
    }
    Solver(vector<int> A, vector<int> B): N((int)A.size()), A(A), B(B), m(N), z(N), p(N), ms(N), zs(N), ps(N) {
        for(int i=1; i<N; ++i) m[i] = A[i] >= B[i-1];
        for(int i=0; i<N; ++i) z[i] = A[i] >= B[i];
        for(int i=0; i<N-1; ++i) p[i] = A[i] >= B[i+1];
        ms[0] = m[0], ps[0] = p[0], zs[0] = z[0];
        for(int i=1; i<N; ++i) ms[i] = ms[i-1] + m[i], ps[i] = ps[i-1] + p[i], zs[i] = zs[i-1] + z[i];
    }
    bool qry(int arm, int brm)
    {
        // cout << "!" << arm << " " << brm << endl;
        if(arm == brm) return all(zs, 0, arm-1) && all(zs, arm+1, N-1);
        else if(arm < brm) return all(zs, 0, arm-1) && all(ms, arm+1, brm) && all(zs, brm+1, N-1);
        else return all(zs, 0, brm-1) && all(ps, brm, arm-1) && all(zs, arm+1, N-1);
    }
};

int main() {
    int T; cin >> T; while(T--) {
        int N, M; cin >> N >> M;
        vector<int> A(N); for(int &i: A) cin >> i;
        sort(A.rbegin(), A.rend()); A.resize(M); reverse(A.begin(), A.end());
        vector<vector<int>> B(M); vector<long long> BS(M, 0LL);
        vector<int> Bv;
        for(int i=0; i<M; ++i)
        {
            int x; cin >> x; B[i].resize(x);
            for(auto& y: B[i]) cin >> y, BS[i] += y;
            Bv.emplace_back((BS[i] + x - 1) / x);
        }
        sort(Bv.begin(), Bv.end());
        Solver s(A, Bv);
        string ans = "";
        for(int i=0; i<M; ++i)
        {
            int x = B[i].size();
            for(auto v: B[i])
            {
                int from = (BS[i] + x - 1) / x;
                int to = ((BS[i] - v) + (x - 2)) / (x-1);
                int fi = lower_bound(Bv.begin(), Bv.end(), from) - Bv.begin();
                int ti = lower_bound(A.begin(), A.end(), to) - A.begin();
                /*for(auto x: A) cout << x << " "; cout << endl;
                for(auto x: Bv) cout << x << " "; cout << endl;
                cout << ti << " " << fi << endl;*/
                if(ti != M && s.qry(ti, fi)) ans.push_back('1');
                else ans.push_back('0');
            }
        }
        cout << ans << '\n';
    }
}