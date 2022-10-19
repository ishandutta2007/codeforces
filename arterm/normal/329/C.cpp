#include <iostream>
#include <vector>
#include <algorithm>

#define M 100100
#define mp make_pair

using namespace std;

int n,m,x[M];
pair<int,int> p[2*M];

void read(void){
    cin>>n>>m;
    for (int x,y,i=0; i<m; ++i){
        cin>>x>>y;
        p[2*i]=mp(x,y);
        p[2*i+1]=mp(y,x);
    }
    sort(p,p+2*m);
}

void kill(void){
    for (int i=0; i<n; ++i)
    x[i]=i+1;
    
    for (int j=0; j<10000; ++j){
        random_shuffle(x,x+n);
        x[n]=x[0];
        
        bool pos=1;
        
        for (int i=0; i<m; ++i)
        if (binary_search(p,p+2*m,mp(x[i],x[i+1]))){
            pos=0;
            break;
        }
        if (!pos)
        continue;
        
        for (int i=0; i<m; ++i)
        cout<<x[i]<<" "<<x[i+1]<<"\n";
        return;
    }
    cout<<"-1\n";
}

int main()
{
    read();
    kill();
    return 0;
}