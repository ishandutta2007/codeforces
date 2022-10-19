#include <bits/stdc++.h>

using namespace std;
vector<int> ans1,ans2;

int main()
{
    int a,b;
    scanf("%d%d",&a,&b) ;


    long long k=0;
    while((k+1)*(k+2)/2<=a+b)   k++;
    for(int i=k;i>=1;i--){
        if(a-i>=0){
            ans1.push_back(i);
            a-=i;
        }
        else if(b-i>=0) {
            ans2.push_back(i);
            b-=i;
        }
    }
	printf("%d\n",ans1.size()) ;
    for(int i=0;i<ans1.size();i++){
        printf("%d ",ans1[i]);
    }
    printf("\n") ; 
    
    printf("%d\n",ans2.size()) ;
    for(int i=0;i<ans2.size();i++){
        printf("%d ",ans2[i]);
    }
    printf("\n") ;
	 
	return 0 ;

}