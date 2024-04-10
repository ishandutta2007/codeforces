#include <bits/stdc++.h>

using namespace std;

main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a;
    cin>>a;
    bool siz=a.size()>=5;
    bool upp=0;
    bool low=0;
    bool dig=0;
    for(int i=0;i<a.size();i++)
        if(isdigit(a[i]))
            dig=1;
        else if(islower(a[i]))
            low=1;
        else if(isupper(a[i]))
            upp=1;
    if(siz && upp && low && dig)
        cout<<"Correct"<<endl;
    else
        cout<<"Too weak"<<endl;
}