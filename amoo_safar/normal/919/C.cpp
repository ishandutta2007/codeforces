#include<iostream>
using namespace std;
int main(){
    int n,m,k;
    cin >> n >> m >> k;
    long long c,t;
    t =0 ;
    string a[2000];
    string b;
    for(int i =0;i<n;i++){
        cin >> b;
        a[i] = b;
        c = 0;
        for(int j = 0;j<m;j++){
            if(b[j]=='*'){
                if(c>=k) t = t+(c-k+1);
                c= 0;
            } else {
                c+=1;
            }
        }
        if(c>=k) t= t+(c-k+1);
    }
    for(int i =0;i<m;i++){
        c = 0;
        for(int j = 0;j<n;j++){
            if(a[j][i]=='*'){
                if(c>=k) t = t+(c-k+1);
                c= 0;
            } else {
                c+=1;
            }
        }
        if(c>=k) t= t+(c-k+1);
    }
    if(k<2) cout << t/2;
    else cout << t;
    return 0;
}