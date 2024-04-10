#include<cstdio>
#include<string>
#include<iostream>
#define N 100100
using namespace std;
string s[N];
int main(){
    int n,i,j,k;
    bool flag=true;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>s[i];
        if(!flag) continue;
        if(s[i].size()<s[i-1].size()) flag=false;
        else if(s[i].size()>s[i-1].size()){
            for(j=0;j<s[i].size();j++){
                if(s[i][j]=='?'){
                    if(j) s[i][j]='0';
                    else s[i][j]='1';
                }
            }
        }
        else{
            for(j=0;j<s[i].size();j++){
                if(s[i][j]=='?') continue;
                if(s[i][j]!=s[i-1][j]) break;
            }
            if(j==s[i].size()||s[i][j]<s[i-1][j]){
                j--;
                while(j>=0&&(s[i][j]!='?'||s[i-1][j]=='9')) j--;
                if(j<0) flag=false;
                else{
                    s[i][j]=s[i-1][j]+1;
                    for(k=0;k<j;k++) s[i][k]=s[i-1][k];
                    for(k=j+1;k<s[i].size();k++){
                        if(s[i][k]=='?') s[i][k]='0';
                    }
                }
            }
            else{
                for(k=0;k<j;k++) s[i][k]=s[i-1][k];
                for(k=j+1;k<s[i].size();k++){
                    if(s[i][k]=='?') s[i][k]='0';
                }
            }
        }
    }
    if(flag){
        puts("YES");
        for(i=1;i<=n;i++) cout<<s[i]<<endl;
    }
    else puts("NO");
}