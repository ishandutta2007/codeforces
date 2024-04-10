#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<=b; ++i)
#define per(i,b,a) for(int i=b; i>=a; --i)
#define mp make_pair
#define pb push_back
#define ms(a, b) memset(a, b, sizeof(a))
#define de(a) cout <<#a <<" => "<<a<<endl
#define dep(a, b) cout <<"("<<a<<","<<b<<")"<<endl
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int>vi;

const int maxn = 2e5+7;
char s[maxn];
int mark[10];
int main(){
    int t;
    scanf("%d", &t);
    while(t--) {
        ms(mark,0);
        int cnt= 0;
        scanf("%s", s+1);
        int len = strlen(s+1);
        rep(i, 1, len) mark[s[i]-'0'] ++;
        rep(i, 0,9) cnt+=mark[i]%2;
        int le=0, flag=0;
        per(i, len, 1) {
            mark[s[i]-'0'] --;
            if(mark[s[i]-'0'] %2) cnt++;
            else cnt--;
            per(j, s[i]-'0'-1, 0) {
                if(j==0 && i==1) break;
                mark[j]++;
                if(mark[j]%2==0) cnt--;
                else cnt++;
                if((le-cnt)%2==0 && le>=cnt){
                    s[i] = j+'0';
                    int p = i+1;
                    while(le>cnt) s[p++] = '9', le--;
                    per(k, 9, 0) {
                        if(mark[k] %2) {
                            s[p++] = k+'0';
                        }
                    }
                    flag=1;
                    break;
                }
                mark[j]--;
                if(mark[j]%2==0) cnt--;
                else cnt++;
            }
            if(flag) break;
            le++;
        }
        if(flag){
            int j=1;
            while(s[j] == '0') j++;
            rep(i, j, len) {
                printf("%c", s[i]);
            }
            puts("");
        } else {
            rep(i, 1, len-2) {
                putchar('9');
            }
            puts("");
        }

    }
    return 0;
}