#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n,cnt[4];
string s,t,tmp;

int main(){
    //freopen("input.txt", "r", stdin);
    cin>>n;
    getline(cin, tmp);
    getline(cin, s);
    getline(cin, t);
    //cout<<s<<endl;
    //cout<<t<<endl;

    for (int i=0; i<2*n; i++){
        if (s[i]=='1' && t[i]=='1'){
            cnt[3]++;
        }
        if (s[i]=='1' && t[i]=='0'){
            cnt[2]++;
        }
        if (s[i]=='0' && t[i]=='1'){
            cnt[1]++;
        }
        else{
            cnt[0]++;
        }

    }
    int ans=0;
    int t=0;
    if (cnt[3]%2){
        ans=1;
        t=1;
    }
    if (cnt[1]>=cnt[2]){
        cnt[1]-=cnt[2];
        cnt[2]=0;
    }
    else{
        cnt[2]-=cnt[1];
        cnt[1]=0;
    }


    //cout<<ans<<endl;

    if (t && cnt[1]){
        ans-=(cnt[1]+1)/2;
    }
    else if (t && cnt[2]){
        ans+=(cnt[2])/2;
    }
    else if (!t && cnt[2]){
        ans+=(cnt[2]+1)/2;
    }
    else if (!t && cnt[1]){
        ans-=(cnt[1])/2;
    }



    if (ans>0){
        cout<<"First"<<endl;
    }
    else if (ans<0){
        cout<<"Second"<<endl;
    }
    else{
        cout<<"Draw"<<endl;
    }
    return 0;
}