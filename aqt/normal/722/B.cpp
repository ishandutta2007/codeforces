#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;

int n, a[120];
string s;
map<char, int> mp;

int main(){

    //manually remove just in case
    /*
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
#endif
*/

    mp['a'] = mp['e'] = mp['i'] = mp['o'] = mp['u'] = mp['y'] = 1;
    
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    getline(cin, s);//throw
    for(int i = 1; i <= n; i++){
        getline(cin, s);
        //cout << i << ' ' << s << '\n';
        int cnt = 0;
        for(char c: s)
            cnt += mp[c];
        if(cnt != a[i]){
            puts("NO");
            return 0;
        }
    }

    puts("YES");
    
    return 0;
}