#include<cstdio>
#include<algorithm>
using namespace std;
#define ST "Stannis"
#define ED "Daenerys"
int main()
{
    int N,K;
    int O=0,E=0;
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++)
    {
        int t;
        scanf("%d",&t);
        if(t%2==0) E++;
        else O++;
    }
    if(N==K)
    {
        if(O%2) puts(ST);
        else puts(ED);
        return 0;
    }
    if(K%2==0 && (N-K)%2==0)
    {
        puts(ED); return 0;
    }
    if(K%2==0 && (N-K)%2==1)
    {
        if((N-K)/2>=min(O,E)) puts(ED);
        else puts(ST);
        return 0;
    }
    if(K%2==1 && (N-K)%2==1)
    {
        if((N-K)/2>=O) puts(ED);
        else puts(ST);
        return 0;
    }
    if(K%2==1 && (N-K)%2==0)
    {
        if( (N-K)/2>=E) puts(ST);
        else puts(ED);
        return 0;
    }
}