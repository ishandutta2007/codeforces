#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

ll n, m, sa, sb;

vector<pii> v, f, s;

int main(){
    
    cin >> n >> m >> sa >> sb;
    
    for(int i = 0,a,b; i < n; i++){
        cin >> a >> b;
        v.push_back({a, b});
    }
    
    ll ly = LLONG_MAX, lx = 0, id = -1;
    ll hx = LLONG_MIN, hy = 0, jd = -1;
    //split into two halves
    for(int i = 0; i < n; i++){
        //bottom right
        if(v[i].second < ly || (v[i].second == ly && v[i].first > lx)){
            ly = v[i].second;
            lx = v[i].first;
            id = i;
        }
        //rightmost
        if(v[i].first > hx){
            hx = v[i].first;
            hy = v[i].second;
            jd = i;
        }
    }
    
    if(id < jd){
        for(int i = 0; i < n; i++){
            if(i >= id && i <= jd)
                s.push_back(v[i]);
            if(i <= id || i >= jd)
                f.push_back(v[i]);
        }
    }
    else{
        for(int i = 0; i < n; i++){
            if(i >= id || i <= jd)
                s.push_back(v[i]);
            if(i <= id && jd <= i)
                f.push_back(v[i]);
        }
    }
    
    f = v; //no difference
    
    /*
    pc('l'); print(id, jd);
    for(auto p: f)
        print(p.first, p.second);
    puts("s");
    for(auto p: s)
        print(p.first, p.second);
    puts("dd");
    */
    //first try first
    ld dis = (ld)m/sb;
    for(auto p: f){
        if(p.first <= 0){
            dis = -1;
            break;
        }
        ld t = (ld)p.first/sa; //bus reaches y-axis
        ld t2 = (ld)p.second/sb;
        //cout << t << ' ' << t2 << '\n';
        //bus closes path first
        if(t < t2){
            dis = -1;
            break;
        }
    }
    
    if(dis != -1){
        printf("%.10Lf\n", dis);
        return 0;
    }
    
    ld lasttime = 0, lasty = 0;
    for(auto p: s){
        //time passed
        if(p.first <= 0)
            continue;
        ld t = (ld)p.first/sa - lasttime;
        lasttime = (ld)p.first/sa;
        lasty = min(lasty + t*sb, (ld)p.second);
        //cout << t << ' ' << lasttime << ' ' << lasty << '\n';
        //the most he can go up
    }
    //cout << lasttime << " , " << lasty << '\n';
    lasttime += (m-lasty)/sb;
    printf("%.10Lf\n", lasttime);
    
    return 0;
}
/*
3 5 2 1
2 1
3 1
3 2
a5.5

3 5 1 2
1 3
2 2
4 1
a6.0

3 5 1 1
-2 2
-1 1
0 2
a5

3 5 1 1
-1 0
2 3
1 0
a6

3 5 1 1
-1 0
3 1
1 0
a7
 */