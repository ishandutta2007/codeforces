// Just say you won't let go
#include <bits/stdc++.h>
#define int long long
#define hash hashhash
#define X first
#define Y second
#define endl "\n"
#define Mp make_pair
using namespace std;
inline int in(){int32_t x ; scanf("%d",&x) ; return x ; }
inline long long lin(){long long x ; scanf("%lld",&x) ; return x ;}
inline string get(){char ch[2000010] ; scanf("%s",ch) ; return ch;}
inline void read(int *a , int n ) { for (int i = 0 ; i < n ; i ++) a[i] = in() ; }
inline int out(int x) {cout << x << endl ; exit(0) ; }
typedef pair<int , int > pii;
typedef long double ld;
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<pii> vii;
const int maxn  = 5e5 + 10;
const int maxm = 1e6 + 10;
const int maxlg = 21;
const int base = 29;
const int mod = 1e9 + 7;
const ll INF = 1e10 + 10;
const int SQ = 317;
int cnt[20],cnt2[20];
int cnt3[20];
int cnt4[20],cnt5[20];
int maxLen;
vector<int> A , B;
int finalZero = -1;
int startDig = -1;
int32_t main()
{
    string num = get();
    int n = (int)num.size();
    for (int i = 0 ; i < n ; i ++) cnt[num[i] - '0'] ++;
    memcpy(cnt2,cnt,sizeof cnt);
    memcpy(cnt3,cnt,sizeof cnt);
    for (int zerocnt = 0 ; zerocnt <= cnt3[0] ; zerocnt ++)
    {
        memcpy(cnt,cnt3,sizeof cnt3);
        memcpy(cnt2,cnt3,sizeof cnt3);
        cnt2[0] -= zerocnt;
        cnt[0] -= zerocnt;
        vector<int> f , s;
        int len = zerocnt;
        memcpy(cnt4,cnt,sizeof cnt);
        memcpy(cnt5,cnt2,sizeof cnt2);
        for (int start = 1 ; start <= 9 ; start ++)
        {
            memcpy(cnt,cnt4,sizeof cnt4);
            memcpy(cnt2,cnt5,sizeof cnt5);
            int need = 10 - start;
            if (!cnt[start] || !cnt2[need]) continue;
            cnt[start] -- , cnt2[need] --;
            int add = 1;
            for (int pt = 0 ; pt <= 9 ; pt ++){
                add += min(cnt[pt],cnt2[9 - pt]);
            }
            if (add + len > maxLen){
                finalZero = zerocnt;
                startDig = start;
                maxLen = add + len;
            }
        }
        if (len > maxLen)
        {
            maxLen = len;
            finalZero = zerocnt;
            startDig = -1;
        }
    }
    if (startDig + finalZero == -2){
        cout << num << endl << num << endl;
        return 0;
    }
    for (int i = 0 ; i < finalZero ; i ++) A.push_back(0) , B.push_back(0);
    memcpy(cnt,cnt3,sizeof cnt3);
    memcpy(cnt2,cnt3,sizeof cnt3);
    cnt[0] -= finalZero , cnt2[0] -= finalZero;
    if (startDig + 1){
        A.push_back(startDig);
        B.push_back(10-startDig);
        cnt[startDig] --;
        cnt2[10 - startDig] --;
        for (int i = 0 ; i <= 9 ; i ++){
            int mini = min(cnt[i],cnt2[9-i]);
            while (mini --){
                A.push_back(i);
                B.push_back(9-i);
                cnt[i] --;
                cnt2[9 - i ] --;
            }
        }
        for (int i = 0 ; i <= 9 ; i ++){
            while (cnt[i] --) A.push_back(i);
            while(cnt2[i] -- )B.push_back(i);
        }
    }else{
        for (int i = 0 ; i <= 9 ; i ++){
            while (cnt[i] --) A.push_back(i);
            while(cnt2[i] -- )B.push_back(i);
        }
    }
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    for (int i = 0 ; i < A.size() ; i ++)
        cout << A[i];
    cout << endl;
    for (int i = 0 ; i < B.size() ; i ++) cout << B[i];
    cout << endl;
}