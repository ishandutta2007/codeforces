#include <bits/stdc++.h>

using namespace std;

 main()
 {
    int k,d;
    cin>>k>>d;
    if(k>1 && !d) cout<<"No solution";
    else cout<<d<<string(k-1,'0');
 }