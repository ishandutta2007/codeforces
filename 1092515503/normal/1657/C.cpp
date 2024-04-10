/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETEMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
int T,n,S;
int rad[1001000],Rpos,Cen;
char t[500100],s[1001000];
void mina(){
    scanf("%d%s",&n,t);
    s[S++]='#',s[S++]='$';
    for(int i=0;i<n;i++)s[S++]=t[i],s[S++]='$';
    s[S++]='#';
    Rpos=Cen=-1;
    for(int i=0;i<S;i++){
        rad[i]=0;
        if(i<=Rpos)rad[i]=min(rad[2*Cen-i],Rpos-i);
        while(i-rad[i]>=0&&i+rad[i]<S&&s[i-rad[i]]==s[i+rad[i]])rad[i]++;
        if(i+rad[i]>Rpos)Rpos=i+rad[i],Cen=i;
    }
    // printf("%s\n",s);
    // for(int i=0;i<S;i++)printf("%d ",rad[i]);puts("");
    int cnt=0,len=n;
    for(int l=0,r;l<n;l=r+1){
        r=l;
        for(int sum=0,mn=0;r<n;r++){
            sum+=(t[r]=='('?1:-1);
            mn=min(mn,sum);
            if(mn>=0&&!sum||r!=l&&rad[r+l+2]>(r-l+1))break;
        }
        // printf("[%d,%d]\n",l,r);
        if(r==n)break;
        len=n-r-1,cnt++;
    }
    printf("%d %d\n",cnt,len);
    S=0;
}
int main(){
    scanf("%d",&T);
    while(T--)mina();
    return 0;
}