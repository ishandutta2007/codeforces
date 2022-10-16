#include <iostream>
#include <deque>

using namespace std;

int v[200005];

int main()
{
    int n,i,t,c;
    cin>>n>>t>>c;

    for(i=1;i<=n;i++)
        cin>>v[i];

    int rasp=0;

    deque<int> coada;
    for(i=1;i<=n;i++)
    {
        while(!coada.empty())
            if(i-coada.front()+1>c)
                coada.pop_front();
            else
                break;


        while(!coada.empty())
            if(v[i]>=v[coada.back()])
                coada.pop_back();
            else
                break;

        coada.push_back(i);
        if(i>=c)
            if(v[coada.front()]<=t)
                rasp++;
    }
    cout<<rasp<<'\n';

    return 0;
}