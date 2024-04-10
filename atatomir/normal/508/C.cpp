#include <iostream>

using namespace std;

#define maxT 700
#define midNight 300

long m,t,r,i,ans,x,cnt;
bool c[maxT];

int main()
{
    cin >> m >> t >> r ;
    if(r>t){
        cout << -1;
        return 0;
    }
    for(;m;m--){
        cin >> x; x += midNight; cnt = 0;
        for(i=x-t;i<x;i++)
            if(c[i]) cnt++;

        i=x-1; cnt = r-cnt;
        while(cnt>0){
            if(c[i]==0){
                c[i]=1;
                cnt--; ans++;
            }
            i--;
        }
    }
    cout << ans;
    return 0;
}