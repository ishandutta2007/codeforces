#include <iostream>

using namespace std;

long n,i,st[100005],dr[100005],a[100005],maxim=0,act;

int main()
{
    cin >> n;
    for(i=1;i<=n;i++) {
        cin >> a[i];
        if(a[i] > a[i-1])
            st[i] = st[i-1]+1;
        else
            st[i] = 1;
    }
    for(i=n;i;i--){
        if(a[i] < a[i+1])
            dr[i] = dr[i+1]+1;
        else
            dr[i] = 1;
    }

    for(i=1;i<=n;i++){
        if(a[i-1]+1<a[i+1]){
            act = st[i-1] + dr[i+1] + 1;
            if(act > maxim) maxim = act;
        } else {
            if(maxim < st[i-1]+1) maxim = st[i-1]+1;
            if(maxim < dr[i+1]+1) maxim = dr[i+1]+1;
        }
    }

    cout << maxim;

    return 0;
}