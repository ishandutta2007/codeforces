#include <iostream>
#include <queue>

#define lint long long int
using namespace std;

int main()
{
    priority_queue<lint> coada;
    lint ans=0;

    int n=0,x;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>x;
        coada.push(x);
    }

    lint a,b;
    while(coada.size()>1){
        a=coada.top();
        coada.pop();
        b=coada.top();
        coada.pop();

        ans+=(a+b);
        coada.push(a+b);
    }

    cout<<ans+coada.top()<<'\n';
    return 0;
}