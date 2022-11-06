#include <iostream>
#include <queue>

using namespace std;

long k,i,n1,n2,n3,t1,t2,t3,last,start;
queue<long> W,D,F;

int main()
{
    cin >> k >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;
    for(i=1;i<=n1;i++) W.push(0);
    for(i=1;i<=n2;i++) D.push(0);
    for(i=1;i<=n3;i++) F.push(0);

    for(i=1;i<=k;i++){
        start = max(max(W.front(),D.front()-t1),F.front()-t1-t2);
        last = max(last,start+t1+t2+t3);

        W.pop(); D.pop(); F.pop();
        W.push(start+t1);
        D.push(start+t1+t2);
        F.push(start+t1+t2+t3);
    }

    cout << last;

    return 0;
}