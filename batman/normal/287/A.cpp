#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s[4];
    for(int i=0;i<4;i++){
        cin>>s[i];
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int cnt1=0,cnt2=0;
            if(s[i][j] == '.')cnt1++;
            else cnt2++;
            if(s[i+1][j] == '.')cnt1++;
            else cnt2++;
            if(s[i][j+1] == '.')cnt1++;
            else cnt2++;
            if(s[i+1][j+1] == '.')cnt1++;
            else cnt2++;
            if(cnt1!=2){cout<<"YES"; return 0;}
        }
    }
    cout<<"NO"; return 0;

}