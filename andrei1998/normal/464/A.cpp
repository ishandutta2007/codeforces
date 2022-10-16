#include <iostream>
#include <string>

using namespace std;

bool ok(string x,int l){
    for(int i=0;i<l-1;i++)
        if(x[i]==x[i+1])
            return 0;

    for(int i=0;i<l-2;i++)
        if(x[i]==x[i+2])
            return 0;

    return 1;
}

string sir;
int p;

string mareste(int poz){
    if(poz==-1)
        return "NO";

    for(sir[poz]++;sir[poz]<=((char)'a'+p-1);sir[poz]++)
        if(ok(sir,poz+1))
            return sir;
    sir[poz]--;

    if(mareste(poz-1)=="NO")
        return "NO";

    for(sir[poz]='a';sir[poz]<=((char)'a'+p-1);sir[poz]++)
        if(ok(sir,poz+1))
            return sir;

    return "NO\n";
}

int main()
{
    int n;
    cin>>n>>p;

    cin>>sir;

    if(p==1){
        cout<<"NO\n";
        return 0;
    }
    else if(p==2){
        if(n==1){
            if(sir=="a")
                cout<<"b\n";
            else
                cout<<"NO\n";
            return 0;
        }

        if(sir=="ab")
            cout<<"ba\n";
        else
            cout<<"NO\n";
        return 0;
    }

    cout<<mareste(n-1)<<'\n';

    return 0;
}