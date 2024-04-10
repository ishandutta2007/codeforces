#include <bits/stdc++.h>
using namespace std;

int n;

vector<long long> ct;
string s;
string l;
bool e=true;
long long cn,cf,cnl,cfl;

bool good(bool lf, bool sf){
    int i=(sf?(int)s.size()-1:0);
    int j=(lf?(int)l.size()-1:0);
    bool g=true;
    while (g&&s[i]==l[j]){
        i+=(sf?-1:1);
        j+=(lf?-1:1);
        if (i<0||i==s.size()) g=false;
        if (j<0||j==l.size()) g=false;
    }
    if (g){
        return(s[i]>l[j]);
    }else{
        if ((i<0||i==s.size())&&!(j<0||j==l.size())) return 0;
    }
    return 1;
}

int main(){
    //cin>>l>>s;
    //cout<<good(0,0)<<" - "<<good(1,0)<<" - "<<good(0,1)<<" - "<<good(1,1);
    cin>>n;
    ct.resize(n);
    for (int i=0; i<n; i++) cin>>ct[i];
    cin>>l;
    cnl=0;
    cfl=ct[0];
    for (int i=1; i<n; i++){
        cin>>s;
        if (e){
            long long f,h;
            f=(cnl!=-1&&good(0,0)?cnl:-1); h=(cfl!=-1&&good(1,0)?cfl:-1);
            //cout<<good(0,0)<<","<<f<<" = "<<s<<endl;
            if (f==-1){
                if (h==-1) cn=-1; else cn=h;
            }else{
                if (h==-1) cn=f; else cn=min(h,f);
            }
            //cn=min((cnl!=-1&&good(0,0)?cnl:-1),(cfl!=-1&&good(1,0)?cfl:-1));
            //cf=min((cnl!=-1&&good(0,1)?cnl+ct[i]:-1),(cfl!=-1&&good(1,1)?cfl+ct[i]:-1));
            f=(cnl!=-1&&good(0,1)?cnl+ct[i]:-1); h=(cfl!=-1&&good(1,1)?cfl+ct[i]:-1);
            if (f==-1){
                if (h==-1) cf=-1; else cf=h;
            }else{
                if (h==-1) cf=f; else cf=min(h,f);
            }
            cfl=cf;
            cnl=cn;
            l=s;
            if (cf==-1&&cn==-1) e=false;
        }
        //cout<<cn<<" - "<<cf<<endl;
    }
    if (cf==-1){
        if (cn==-1) cout<<-1; else cout<<cn;
    }else{
        if (cn==-1) cout<<cf; else cout<<min(cn,cf);
    }
    return 0;
}