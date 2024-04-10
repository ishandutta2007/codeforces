#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)

const int maxn = 1e5 + 2;
const int maxp = 100 + 2;
const int inf = 1e9;

struct node{
    long long dp;
    int i;
    double x;
    node(){}
    node(long long dp, int i, double x): dp(dp), i(i), x(x) {}; 
};

vector < int > event;
node stack[maxn];
long long dp[maxp][maxn];
int sum[maxn];
int d[maxn];
long long pref[maxn];
int n, m, p;
    
long long getsum(int l, int r){
//  return pref[l] - pref[r] - (m - 1 - r) * 1ll * event[m - 1];
//  epr("l r:  %d %d\n", l, r);
    l++;
    return pref[l] - pref[r] - (r - l) * 1ll * (event[m - 1] - event[r]);
}

long long fastsolve(){
    sort(event.begin(), event.end());
    
    pref[0] = 0; 
    for (int i = m - 2; i >= 0; i--)
        pref[i] = pref[i + 1] + (event[m - 1] - event[i]);
//      pref[i] = pref[i + 1] + (m - 1 - i) * 1ll * (event[i + 1] - event[i]);
    
    for (int i = 1; i < m; i++)
        dp[0][i] = dp[0][i - 1] + i * 1ll * (event[i] - event[i - 1]);
    
//  for (int i = 0; i < m; i++)
//      cerr << pref[i] << " ";
//  cerr << endl;
//  
//  for (int i = 0; i < m; i++)
//      cerr << event[i] << " ";
//  cerr << endl << endl;
//  
    for (int i = 1; i < p; i++){
        int k = 0;
        int cur = 0;
        stack[cur++] = node(dp[i - 1][i - 1], i - 1, -inf);
        for (int j = i; j < m; j++){
            for (; k + 1 < cur && stack[k + 1].x < event[j]; k++);
//          epr("k :  %d\n", k);
            dp[i][j] = stack[k].dp + getsum(stack[k].i, j);         
    /*      if (i == 2 && j == 2){
                cerr << "getsum " << getsum(stack[k].i, j) << endl;
                cerr << "dp: " << dp[i][j] << endl;
            }
    */      for (; cur > 0 && stack[cur - 1].x > event[j] + (dp[i - 1][j] - stack[cur - 1].dp - getsum(stack[cur - 1].i, j)) * 1.0 / (j - stack[cur - 1].i); cur--)
                assert(cur > 0);
            stack[cur] = node(dp[i - 1][j], j, event[j] + (dp[i - 1][j] - stack[cur - 1].dp - getsum(stack[cur - 1].i, j)) * 1.0 / (j - stack[cur - 1].i));
            cur++;
            
//          epr("cur %d\n", cur);
//          cerr << stack[cur - 1].dp << " " << stack[cur - 1].i << " " << stack[cur - 1].x << "\n\n";
        
            k = min(k, cur - 1);
            
        }
    }
//  cerr << endl;
//  for (int i = 0; i < p; i++){
//      for (int j = 0; j < m; j++)
//          cerr << dp[i][j] <<  " ";
//      cerr << "\n";       
//  }
//  
    return dp[p - 1][m - 1];
}

void reading(){
    int h, t;
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 0; i < n - 1; i++)
        scanf("%d", &d[i]);
    sum[0] = 0;
    for (int i = 0; i < n - 1; i++)
        sum[i + 1] = sum[i] + d[i];
    for (int i = 0; i < m; i++){
        scanf("%d%d", &h, &t);
        event.pb(t - sum[h - 1]);
    }   
}

// void gen(){
//  int n = 3 + rand() % 5;
//  int m = 3 + rand() % 5;
//  int p = 1 + rand() % 5;
//  for (int i = 0; i < 
// }

// void stress(){
//  for (int i = 0; i < 5; i++){
//      epr("test: %d\n", i);
//      gen();
//      ans1 = fastsolve();
//      ans2 = slowsolve();
//      if (ans1 != ans2){
//          cerr << "answers :   " << ans1 << " " << ans2 << end;
//          
//      }
//      
//  }
//  
//  
// }

int main(){
//     freopen("in", "r", stdin);
//     freopen("out", "w", stdout);
  /*  if (0)
        stress();
    */reading();
    cout << fastsolve() << endl;
    
    return 0;
}