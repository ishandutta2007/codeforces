#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int main(){
    
    set<long long> s;

    int n,k;
    scanf("%d %d",&n,&k);
    for(int i = 0; i < n; i++){
        int foo;
        scanf("%d",&foo);
        s.insert((long long)foo);
    }
    if(k == 1){
        printf("%d\n",n);
        return 0;
    }
    set<long long>::iterator it;
    for(it = s.begin(); it != s.end(); it++){
        int cont = 0;
        if(*it%k == 0)
            if(s.find(*it/k) != s.end()) cont++;
        if(s.find((*it) * k) != s.end()) cont++;
        if(cont == 2) s.erase(it);
        if(cont == 1) s.erase((*it) * k);
    }

    printf("%d\n",s.size());



}