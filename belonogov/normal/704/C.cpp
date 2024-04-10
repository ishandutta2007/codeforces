#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 5e5 + 10;
const long long INF = 1e9 + 19;
const int MOD = 1e9 + 7;

struct Var {
    int id, type;
    Var(): id(-1), type(-1) { }
    Var(int id, int type):id(id), type(type) { }
};

int n, m;
vector < vector < Var > > a;
vector < int > where[N];
long long dp0 = 1, dp1 = 0;
int use[N];
vector < int > allCl;

void read() {
    scanf("%d%d", &m, &n);
    a.resize(m);
    for (int i = 0; i < m; i++) {
        int k;
        scanf("%d", &k);
        a[i].resize(k);
        for (int j = 0; j < k; j++) {
            int x;
            scanf("%d", &x);
            a[i][j] = Var(abs(x) - 1, x > 0);
        }
    }
}


void printChain(vector < vector < Var > > chain) {
    for (auto cl: chain) {
        cerr << "(";
        for (auto x: cl)
            cerr << "[" << x.id << ", " << x.type << "] ";

        cerr << ")\n";
    }

}



void updDP(long long c0, long long c1) {
    long long t0, t1;
    t0 = (dp0 * c0 + dp1 * c1) % MOD;
    t1 = (dp1 * c0 + dp0 * c1) % MOD;
    dp0 = t0;
    dp1 = t1;
}

void updM(long long & a, long long b) {
    a = (a + b) % MOD;
}


void dfs1(int cl) {
    use[cl] = 1; 
    allCl.pb(cl);
    for (auto x: a[cl]) {
        if (where[x.id].size() == 2) {
            int next = where[x.id][0] + where[x.id][1] - cl;
            if (use[next] == 0) 
                dfs1(next);
        }
    }
}

void dfs2(int cl, vector < vector < Var > > & chain) {
    use[cl] = 2;
    chain.pb(a[cl]);
    for (auto x: a[cl]) {
        if (where[x.id].size() == 2) {
            int next = where[x.id][0] + where[x.id][1] - cl;
            if (use[next] < 2) 
                dfs2(next, chain);
        }
    }
}


pair < int, int > solver(vector < vector < Var > > chain) {
    int n = chain.size();
	//printChain(chain);
    if (n == 0) {
        return mp(1, 0);
    }
	if (n == 1) {
		if (chain[0].size() == 1)
			return mp(1, 1);
		if (chain[0][0].id != chain[0][1].id)
			return mp(1, 3);
		if (chain[0][0].type != chain[0][1].type)
			return mp(2, 0);
		return mp(1, 1);
	}
    vector < long long > dp[2][2];
    vector < int > com(n - 1);
    vector < int > type(n - 1);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            dp[i][j].resize(n);

    for (int i = 0; i < n - 1; i++) {
        int cc = 0;
        for (auto x: chain[i])
            for (auto y: chain[i + 1])
                if (x.id == y.id)  {
                    cc++;
                    com[i] = x.id;
                    type[i] = x.type ^ y.type;
                }
		//db(cc);
        assert(cc == 1);
    }

    if (chain[0].size() == 1) {
        dp[0][0][0] = 1;
    }
    else {
        dp[0][0][0] = 1; 
        dp[1][1][0] = 1; 
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < 2; j++) // cnt % 2
            for (int k = 0; k < 2; k++) { // last block
                if (type[i] == 0) {
                    updM(dp[j ^ 1 ^ (k == 0)][1][i + 1], dp[j][k][i]);
                    updM(dp[j][0][i + 1], dp[j][k][i]);
                }
                else {
                    updM(dp[j ^ (k == 0)][0][i + 1], dp[j][k][i]);
                    updM(dp[j ^ 1][1][i + 1], dp[j][k][i]);
                }
            }
    }

    long long dpr[2];
    memset(dpr, 0, sizeof(dpr));
    for (int j = 0; j < 2; j++)
        for (int k = 0; k < 2; k++)  {
            if (chain.back().size() == 1) { 
                updM(dpr[j], dp[j][k][n - 1]);
            }
            else {
                updM(dpr[j], dp[j][k][n - 1]);
                updM(dpr[j ^ (k == 0)], dp[j][k][n - 1]);
            }
        }
    
    return mp(dpr[0], dpr[1]);
}

pair < int, int > solverC(vector < vector < Var > > chain) {
    int n = chain.size();
    if (n == 1) {
        if (chain[0].size() == 1) {
            return mp(1, 1);
        }
        if (chain[0][0].type == chain[0][1].type)
            return mp(1, 1);
        else
            return mp(0, 2);
    }
    //printChain(chain);
    if (n == 2) {
        int dpr[2];
        memset(dpr, 0, sizeof(dpr));
        for (int mask = 0; mask < 4; mask++) {
            int cc = 0; 
            int x = chain[0][0].id;
            int y = chain[0][1].id;
            int r1 = mask & 1;
            int r2 = (mask >> 1) & 1;
            assert(x != y);
            for (int i = 0; i < n; i++) {
                bool flag = 0;
                for (int j = 0; j < 2; j++) {
                    if (chain[i][j].id == x) 
                        flag |= r1 ^ chain[i][j].type ^ 1;
                    if (chain[i][j].id == y) 
                        flag |= r2 ^ chain[i][j].type ^ 1;
                }
                cc ^= flag;
            }
            dpr[cc]++;
        } 
        //db("tut");
        return mp(dpr[0], dpr[1]);
    }


    vector < int > com(n);
    vector < int > type(n);
    //db(n);
    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;
        int cc = 0;
        for (auto x: chain[i])
            for (auto y: chain[next])
                if (x.id == y.id) {
                    com[i] = x.id;
                    type[i] = x.type ^ y.type;
                    cc++;
                }
        //db(cc);
        assert(cc == 1);
    }

    int myVar = com[n - 1]; 
    long long dpr[2];  
    memset(dpr, 0, sizeof(dpr));
      
	//db(myVar + 1);
    for (int value = 0; value <= 1; value++) {
        //db(value);
        auto tmp = chain;
        int cc = 0;
        for (int i = 0; i < 2; i++)
           if (tmp[0][i].id == myVar) {
               if ((tmp[0][i].type ^ 1) ^ value) {
                   tmp.erase(tmp.begin());
                   cc ^= 1;
               }
               else {
                   tmp[0].erase(tmp[0].begin() + i);
               }
               break;
           } 

        for (int i = 0; i < 2; i++)
           if (tmp.back()[i].id == myVar) {
               if ((tmp.back()[i].type ^ 1) ^ value) {
                   tmp.erase(tmp.end() - 1);
                   cc ^= 1;
               }
               else {
                   tmp.back().erase(tmp.back().begin() + i);
               }
               break;
           } 

        auto res = solver(tmp);
		if (cc)
			swap(res.fr, res.sc);
		//db2(res.fr, res.sc);
        updM(dpr[0], res.fr);
        updM(dpr[1], res.sc);
    }


    return mp(dpr[0], dpr[1]);
}

long long ff(int n, long long res) {
    long long answer = 1;
    for (int i = 0; i < n; i++)
        answer =  (answer * 2) % MOD;
    return (answer - res + MOD) % MOD;
}

long long solve() {
	dp0 = 1;
	dp1 = 0;
    memset(use, 0, sizeof(use));
    for (int i = 0; i < n; i++)
        where[i].clear();


    for (int i = 0; i < m; i++)
        for (auto x: a[i]) 
            where[x.id].pb(i);
    
    for (int i = 0; i < n; i++) {
        assert(where[i].size() <= 2);
        if (where[i].empty()) {
            updDP(2, 0); 
        }
        else {
            int close = where[i][0];
            if (use[close] == 0) {
                allCl.clear();
                dfs1(close);
                
                set < int > allVar;
                for (auto cl: allCl)
                    for (auto x: a[cl])
                        allVar.insert(x.id);
                //if (allCl.size() == 1) {
                    //int clId = allCl[0];  

                //}

                //db2(allCl.size(), allVar.size());
                //assert(allVar.size() >= allCl.size());

                set < int > border;
                for (auto cl: allCl)
                    if (a[cl].size() == 1) 
                        border.insert(cl);
                for (auto var: allVar)
                    if (where[var].size() == 1) 
                        border.insert(where[var][0]);

                if (!border.empty()) {
                    
                    assert(border.size() == 2 || (allCl.size() == 1 && border.size() == 1));

                    int bgCl = *border.begin();
                    vector < vector < Var > > chain;
                    dfs2(bgCl, chain);
                    auto res = solver(chain); // c0, c1
					//db2(res.fr, res.sc);
                    updDP(res.fr, res.sc);
                }
                else {
					//db("tut");
					assert(allCl.size() == allVar.size());
                    vector < vector < Var > > chain;
                    dfs2(allCl[0], chain);
                    auto res = solverC(chain);
					//db2(res.fr, res.sc);
                    updDP(res.fr, res.sc);
                }

            }

        }

    }
	//db2(dp0, dp1);

    

    
    return ff(n, dp0);
}


int stupid() {
    int answer = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        int cc = 0;                
        for (int i = 0; i < m; i++) {
            bool flag = 0;
            for (int j = 0; j < (int)a[i].size(); j++)
                flag |= (a[i][j].type ^ ((mask >> a[i][j].id) & 1) ^ 1);
            cc ^= flag;
        }
        if (cc == 0)
            answer++;
    }
    return ff(n, answer);
}

void printAns(long long res) {
    cout << res << endl;
}

void printTest() {
	cout << m << " " << n << endl;	
	for (int i = 0; i < m; i++) {
		cout << a[i].size() << " ";
		for (auto x: a[i]) {
			int cof = (x.type == 0)? -1: 1;
			cout << (x.id + 1) * cof << " ";
		}
		cout << endl;

	}
}

void stress() {
	for (int tt = 0; ; tt++) {
		db2("testId", tt);
		for (;;) {
			n = 10;
			m = 8; 
			a.resize(m);
			map < int, int > q;
			for (int i = 0; i < m; i++) {
				int k = rand() % 2 + 1;
				a[i].resize(k);
				for (int j = 0; j < k; j++)   {
					a[i][j] = Var(rand() % n, rand() % 2);
					q[a[i][j].id]++;
				}
			}
			bool flag = 1;
			for (auto x: q)
				flag &= x.sc <= 2;

			if (flag)
				break;
		}
		//printTest();
		int r1 = solve();
		int r2 = stupid();
		//db2(r1, r2);
		assert(r1 == r2);
	} 


}


int main(){
#ifdef MY_DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            //db(stupid());
            printAns(solve());
        }
    }
    else {
        stress();
    }

    return 0;
}