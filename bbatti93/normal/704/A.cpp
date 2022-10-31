#include <bits/stdc++.h>

using namespace std;

int n, q, ki, last=0, db[300001], t, a, l=0, tip[300001];
bool volt[300001];
stack<int> s[300001];


int main()
{
    scanf("%d%d", &n, &q);
    for(int i=0;i<q;i++) {
        scanf("%d%d", &t, &a);
        if(t==1) {
            l++;
            ki++;
            s[a].push(l);
        }
        if(t==2) {
            while(!s[a].empty()) {
                if(!volt[s[a].top()]) {
                    volt[s[a].top()]=true;
                    ki--;
                }
                s[a].pop();
            }
        }
        if(t==3) {
            if(last>=a) {
                printf("%d\n",ki);
                continue;
            }
            for(int j=last+1;j<=a;j++) {
                if(!volt[j]) {
                    volt[j]=true;
                    ki--;
                }
            }
            last=a;
        }
        printf("%d\n",ki);
    }
    return 0;
}