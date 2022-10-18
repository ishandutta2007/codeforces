#include<iostream>
#include<cmath>
int N,R,K,A;
main(){
	std::cin>>N;
	while(N--)
                {std::cin>>K>>A;
		A=log2(A)/2+0.999999999;
		K+=A?A:1;
		R=R<K?K:R;}
	std::cout<<R;
}