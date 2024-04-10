#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
// #define int long long int
#define pb push_back
#define fi first
#define se second
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define IO ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
const int mod = 1e9 + 7;
const int mod1 = 998244353;
typedef long double f80;
#ifndef LOCAL
#define endl '\n'
#endif
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int c[5] = {25, 25, 25, 25, 15};
vector<int> idx[3];
vector<int> lol[10];
vector<int> ans;
void solve(){
    int a, b;
    cin >> a >> b;
    bool poss = 0;
    fr(i, 0, 9)
        lol[i].clear();
    for(int mask = 0; mask < 1024; mask++){
        ans.clear();
        ans.resize(10, 0);
        idx[0].clear();
        idx[1].clear();
        idx[2].clear();
        int m = mask, l = mask % 5;
        int aa = a, bb = b;
        int c1 = 0, c2 = 0;
        int f1 = 0, f2 = 0, f3 = 0;
        int max1 = 0, max2 = 0;
        for(int i = 0; i < 5; i++){
            if(l == 0 || l == 1)
                c1++;
            else c2++;
            if(l == 0){
                aa -= (c[i] + 1);
                bb -= (c[i] - 1);
                ans[i] += (c[i] + 1);
                ans[i + 5] += (c[i] - 1);
                idx[0].pb(i);
                f3++;
            }
            else if(l == 1){
                aa -= c[i];
                max2 += (c[i] - 2);
                ans[i] += c[i];
                idx[2].pb(i);
                f2++;
            }
            else if(l == 2){
                aa -= (c[i] - 1);
                bb -= (c[i] + 1);
                ans[i] += (c[i] - 1);
                ans[i + 5] += (c[i] + 1);
                idx[0].pb(i);
                f3++;
            }
            else{
                max1 += (c[i] - 2);
                bb -= c[i];
                ans[i + 5] += c[i];
                idx[1].pb(i);
                f1++;
            }
            if(c1 == 3 || c2 == 3) break;
            m /= 4;
            l = m % 4;
        }
        if(!lol[5 + c1 - c2].empty()) continue;
        if(aa < 0 || bb < 0) continue;
        if(f3 == 0){
            if(aa > max1 || bb > max2) continue;
            for(int x : idx[1]){
                if(aa > c[x] - 2){
                    aa -= (c[x] - 2);
                    ans[x] += (c[x] - 2);
                }
                else{
                    ans[x] += aa;
                    aa = 0;
                    break;
                }
            }
            for(int x : idx[2]){
                if(bb > c[x] - 2){
                    bb -= (c[x] - 2);
                    ans[x + 5] += (c[x] - 2);
                }
                else{
                    ans[x + 5] += bb;
                    bb = 0;
                }
            }
        }
        else{
            if(aa > bb){
                if(aa - bb > max1) continue;
                for(int x : idx[1]){
                    if(aa - bb > c[x] - 2){
                        aa -= (c[x] - 2);
                        ans[x] += (c[x] - 2);
                    }
                    else{
                        ans[x] += aa - bb;
                        aa = bb;
                        break;
                    }
                }
            }
            else{
                if(bb - aa > max2) continue;
                for(int x : idx[2]){
                    if(bb - aa > c[x] - 2){
                        bb -= (c[x] - 2);
                        ans[x + 5] += (c[x] - 2);
                    }
                    else{
                        ans[x + 5] += bb - aa;
                        bb = aa;
                    }
                }
            }
            for(int x : idx[0]){
                if(aa){
                    ans[x] += aa;
                    ans[x + 5] += aa;
                    break;
                }
            }
        }
        poss = 1;
        lol[5 + c1 - c2] = ans;
    }
    if(!poss){
        cout << "Impossible" << endl;
        return;
    }
    for(int j = 9; j >= 0; j--){
        if(!lol[j].empty())
        {
            int c1 = 0, c2 = 0;
            fr(i, 0, 4){
                if(lol[j][i] > lol[j][i + 5])
                    c1++;
                else
                    c2++;
                if(c1 == 3 || c2 == 3) break;
            }
            cout << c1 << ":" << c2 << endl;
            fr(i, 0, c1 + c2 - 1){
                cout << lol[j][i] << ":" << lol[j][i + 5] << " ";
            }
            cout << endl;
            break;
        }
    }
}


signed main()
{
    IO;
    #ifdef LOCAL
        freopen("inp.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif
    clock_t clk = clock();
    int t;
    cin >> t;
    // t = 1;
    fr(i, 1, t){
        solve();
    }
    cerr << endl << setprecision(10) << fixed << (double)(clock() - clk) / CLOCKS_PER_SEC;
    return 0;
}