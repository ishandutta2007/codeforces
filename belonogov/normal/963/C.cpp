#include <bits/stdc++.h>


using namespace std;
typedef long long ll;

const int MOD = 1e9 + 9;

ll getDiv(ll go) {
    assert(go <= 1.01e12);
    ll answer = 0;
    for (ll i = 1; i * i <= go; i++) {
        if (go % i == 0) {
            answer += 2;
            if (i * i == go) {
                answer -= 1;
            }
        }
    }
    return answer;
}


int main() {
#ifdef HOME
    freopen("A.in", "r", stdin);
#endif 
    int n;
    scanf("%d", &n);
    map<ll,ll> A, B;

    ll area = 0;
    struct rect {
        ll w, h, c;
    };
    vector<rect> rt;
    set<pair<ll,ll>> have;
    for (int i = 0; i < n; i++) {
        ll w, h, c;
        scanf("%lld%lld%lld", &w, &h, &c);
        A[w] += c;
        B[h] += c;
        area += c;
        have.insert({w, h});
        rt.push_back({w, h, c});
    }
    
    ll gcdA = 0, gcdB = 0;
    for (auto x: A) {
        gcdA = __gcd(x.second, gcdA);
    }
    for (auto x: B) {
        gcdB = __gcd(x.second, gcdB);
    }

    //cerr << "a b: " << gcdA << " " << gcdB << endl;

    assert(area % gcdA == 0);
    assert(area % gcdB == 0);

    bool fail = 0;

    for (auto x: A) {
        if (fail) break;;
        for (auto y: B) {
            if (have.count({x.first, y.first}) == 0) {
                fail = 1;
                break;
            }
        }
    }

    ll go = -1;
    for (auto x: rt) {
        ll cntA = A[x.w];
        ll cntB = B[x.h];
        assert(cntA % gcdA == 0);
        assert(cntB % gcdB == 0);
        cntA /= gcdA;
        cntB /= gcdB;
        if (cntA * 1.0 * cntB > x.c) {
            fail = 1;
        }
        else {
            if (x.c % (cntA * cntB) != 0) {
                fail = 1;
            }
            else {
                ll tmp = x.c / (cntA * cntB);
                if (go == -1 || go == tmp) {
                    go = tmp;
                }
                else {
                    fail = 1;
                }
            }
        }
    }


    if (fail) {
        puts("0"); 
        return 0;
    }
    cout << getDiv(go) << endl;
    


}