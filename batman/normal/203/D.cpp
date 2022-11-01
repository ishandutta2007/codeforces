#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
int main(){
    ld a,b,m; cin>>a>>b>>m;
    ld vx,vy,vz; cin>>vx>>vy>>vz;
    ld t= m/vy; t=t*-1;
    ld x=a/2 + t*vx;
    ld z=vz*t;
    if(x>=0){
        int c=x/a;
        if(c%2==0){x=x-(ld)a*(c);}else{x=a-(x-(ld)a*c);}
    }else{
        x=x*(-1);
        int c=x/a;
        if(c%2==0){x=x-(ld)a*(c);}else{x=a-(x-(ld)a*c);}
    }
    if(z>=0){
        int d=z/b;
        if(d%2==0){z=z-(ld)b*(d);}else{z=b-(z-(ld)b*d);}
    }else{
        z=z*(-1);
        int d=z/b;
        if(d%2==0){z=z-(ld)b*(d);}else{z=b-(z-(ld)b*d);}
    }
    cout<<fixed<<setprecision(10)<<x<<" "<<z; return 0;
}