#include <iostream>

using namespace std;

long ans[1005][1005],n,k,d,ok,i,j;

void Solve(long pas,long bg,long en){
    if(pas > d) return ;
    if(en-bg+1 <= 1){
        if(bg > en) return ;
        for(long i=pas;i<=d;i++) ans[i][bg] = 1;
        return ;
    }

    long dim = en-bg+1,i,j;
    long lung = dim/k,bonus = dim % k,pos=bg-1;

    for(i=1;i<=k;i++){
        if(pos >= en) break;

        long gogogo = lung + (bonus > 0?1:0); bonus--;
        long def= gogogo;
        for(;gogogo;gogogo--){
            pos++;
            ans[pas][pos]=i;
        }
        Solve(pas+1,pos-def+1,pos);
    }
}

long notOk(){
    long nl = n;
    for(long i=1;i<=d;i++){
        nl = (nl + (k-1))/k;
    }
    if(nl > 1) return 1;
    return 0;
}

int main()
{
    cin >> n >> k >> d;
    if(notOk()){
        cout << -1;
        return 0;
    }
    Solve(1,1,n);

    for(i=1;i<=d;i++){
        for(j=1;j<=n;j++) cout << ans[i][j] << ' ';
        cout << '\n';
    }


    return 0;
}