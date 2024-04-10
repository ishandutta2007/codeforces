#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, a[4];
    cin>>n;
    for(int i=0;i<n;++i) cin>>a[i];
    sort(a,a+n);

    if(n==0) cout<<"YES\n1\n1\n3\n3";
    else if(n==1) cout<<"YES\n"<<a[0]<<'\n'<<(3*a[0])<<'\n'<<(3*a[0]);
    else if(n==2){
        if(a[1]>(3*a[0])) cout<<"NO";
        else cout<<"YES\n"<<((4*a[0])-a[1])<<'\n'<<(3*a[0]);
    }
    else if(n==3){
        if(((a[2]%3)==0)&&((a[0]+a[1])==(4*(a[2]/3))))
            cout<<"YES\n"<<(a[2]/3);
        else if((a[2]==(3*a[0]))&&(((4*a[0])-a[1])<a[2]))
            cout<<"YES\n"<<((4*a[0])-a[1]);
        else if((a[2]<=(3*a[0]))&&(((4*a[0])==(a[1]+a[2]))))
            cout<<"YES\n"<<(3*a[0]);
        else cout<<"NO";
    }
    else if(n==4){
        if((a[3]==(3*a[0]))&&((4*a[0])==(a[1]+a[2]))) cout<<"YES";
        else cout<<"NO";
    }
    return 0;
}