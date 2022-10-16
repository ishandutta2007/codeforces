#include <iostream>
#include <set>

using namespace std;

int convert(int x,int a,int b) //Convert x = 100001010 : 0 = a && 1 = b
{
    int ans=0;
    for(int i=0,j=1;i<9;i++,j*=10)
        if(x&(1<<i))
            ans+=(j*b);
        else{
            if(!(x-(x&((1<<i)-1))))
                break;
            ans+=(j*a);
        }

    return ans;
}

set<int> toate;

int main()
{
    int n,ans=0;

    cin>>n;
    if(n==1000000000)
        ans=1;

    for(int a=0;a<10;a++)
        for(int b=0;b<10;b++){
            for(int i=1;i<(1<<9);i++){
                int aux=convert(i,a,b);

                if(aux==0 || aux>n)
                    continue;

                if(!toate.count(aux)){
                    toate.insert(aux);
                    ans++;
                }
            }
        }

    cout<<ans<<'\n';
    return 0;
}