#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);

    set<int> tr;
    while(tr.find(n)==tr.end()) {
        tr.insert(n);
        n+=1;
        while(n%10==0) n/=10;
    }
    printf("%d\n",(int)tr.size());
    
    return 0;
}