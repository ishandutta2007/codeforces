#include<iostream>
#include<sstream>
#include<fstream>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<string.h>
#include<math.h>
#include<cassert>
#include<iomanip>
#include<utility>
#include<bitset>
#include<set>
#include<map>
#include<list>
#include<queue>
#include<deque>
#include<stack>
#include<vector>
#include<functional>
#include<algorithm>
#include<memory.h>
#include<assert.h>
#include<numeric>
#include<limits.h>
using namespace std;
int n;
int main(){
	cin>>n;
	cout<<"+------------------------+"<<endl;
	if(n==0){
		cout<<"|#.#.#.#.#.#.#.#.#.#.#.|D|)"<<endl;
		cout<<"|#.#.#.#.#.#.#.#.#.#.#.|.|"<<endl;
		cout<<"|#.......................|"<<endl;
		cout<<"|#.#.#.#.#.#.#.#.#.#.#.|.|)"<<endl;
	}
	else if(n==1){
		cout<<"|O.#.#.#.#.#.#.#.#.#.#.|D|)"<<endl;
		cout<<"|#.#.#.#.#.#.#.#.#.#.#.|.|"<<endl;
		cout<<"|#.......................|"<<endl;
		cout<<"|#.#.#.#.#.#.#.#.#.#.#.|.|)"<<endl;
	}
	else if(n==2){
		
		cout<<"|O.#.#.#.#.#.#.#.#.#.#.|D|)"<<endl;
		cout<<"|O.#.#.#.#.#.#.#.#.#.#.|.|"<<endl;
		cout<<"|#.......................|"<<endl;
		cout<<"|#.#.#.#.#.#.#.#.#.#.#.|.|)"<<endl;
	}
	else if(n==3){
		
		cout<<"|O.#.#.#.#.#.#.#.#.#.#.|D|)"<<endl;
		cout<<"|O.#.#.#.#.#.#.#.#.#.#.|.|"<<endl;
		cout<<"|O.......................|"<<endl;
		cout<<"|#.#.#.#.#.#.#.#.#.#.#.|.|)"<<endl;
	}
	else if(n==4){
		
		cout<<"|O.#.#.#.#.#.#.#.#.#.#.|D|)"<<endl;
		cout<<"|O.#.#.#.#.#.#.#.#.#.#.|.|"<<endl;
		cout<<"|O.......................|"<<endl;
		cout<<"|O.#.#.#.#.#.#.#.#.#.#.|.|)"<<endl;
	}
	else if(n==5){
		
		cout<<"|O.O.#.#.#.#.#.#.#.#.#.|D|)"<<endl;
		cout<<"|O.#.#.#.#.#.#.#.#.#.#.|.|"<<endl;
		cout<<"|O.......................|"<<endl;
		cout<<"|O.#.#.#.#.#.#.#.#.#.#.|.|)"<<endl;
	}
	else if(n==6){
		
		cout<<"|O.O.#.#.#.#.#.#.#.#.#.|D|)"<<endl;
		cout<<"|O.O.#.#.#.#.#.#.#.#.#.|.|"<<endl;
		cout<<"|O.......................|"<<endl;
		cout<<"|O.#.#.#.#.#.#.#.#.#.#.|.|)"<<endl;
	}
	else if(n==7){
		
		cout<<"|O.O.#.#.#.#.#.#.#.#.#.|D|)"<<endl;
		cout<<"|O.O.#.#.#.#.#.#.#.#.#.|.|"<<endl;
		cout<<"|O.......................|"<<endl;
		cout<<"|O.O.#.#.#.#.#.#.#.#.#.|.|)"<<endl;
	}
	else if(n==8){
		
		cout<<"|O.O.O.#.#.#.#.#.#.#.#.|D|)"<<endl;
		cout<<"|O.O.#.#.#.#.#.#.#.#.#.|.|"<<endl;
		cout<<"|O.......................|"<<endl;
		cout<<"|O.O.#.#.#.#.#.#.#.#.#.|.|)"<<endl;
	}
	else if(n==9){
		
		cout<<"|O.O.O.#.#.#.#.#.#.#.#.|D|)"<<endl;
		cout<<"|O.O.O.#.#.#.#.#.#.#.#.|.|"<<endl;
		cout<<"|O.......................|"<<endl;
		cout<<"|O.O.#.#.#.#.#.#.#.#.#.|.|)"<<endl;
	}
	else if(n==10){
		
		cout<<"|O.O.O.#.#.#.#.#.#.#.#.|D|)"<<endl;
		cout<<"|O.O.O.#.#.#.#.#.#.#.#.|.|"<<endl;
		cout<<"|O.......................|"<<endl;
		cout<<"|O.O.O.#.#.#.#.#.#.#.#.|.|)"<<endl;
	}
	else if(n==11){
		
		cout<<"|O.O.O.O.#.#.#.#.#.#.#.|D|)"<<endl;
		cout<<"|O.O.O.#.#.#.#.#.#.#.#.|.|"<<endl;
		cout<<"|O.......................|"<<endl;
		cout<<"|O.O.O.#.#.#.#.#.#.#.#.|.|)"<<endl;
	}
	else if(n==12){
		
		cout<<"|O.O.O.O.#.#.#.#.#.#.#.|D|)"<<endl;
		cout<<"|O.O.O.O.#.#.#.#.#.#.#.|.|"<<endl;
		cout<<"|O.......................|"<<endl;
		cout<<"|O.O.O.#.#.#.#.#.#.#.#.|.|)"<<endl;
	}
	else if(n==13){
		
		cout<<"|O.O.O.O.#.#.#.#.#.#.#.|D|)"<<endl;
		cout<<"|O.O.O.O.#.#.#.#.#.#.#.|.|"<<endl;
		cout<<"|O.......................|"<<endl;
		cout<<"|O.O.O.O.#.#.#.#.#.#.#.|.|)"<<endl;
	}
	else if(n==14){
		
		cout<<"|O.O.O.O.O.#.#.#.#.#.#.|D|)"<<endl;
		cout<<"|O.O.O.O.#.#.#.#.#.#.#.|.|"<<endl;
		cout<<"|O.......................|"<<endl;
		cout<<"|O.O.O.O.#.#.#.#.#.#.#.|.|)"<<endl;
	}
	else if(n==15){
		
		cout<<"|O.O.O.O.O.#.#.#.#.#.#.|D|)"<<endl;
		cout<<"|O.O.O.O.O.#.#.#.#.#.#.|.|"<<endl;
		cout<<"|O.......................|"<<endl;
		cout<<"|O.O.O.O.#.#.#.#.#.#.#.|.|)"<<endl;
	}
	else if(n==16){
		
		cout<<"|O.O.O.O.O.#.#.#.#.#.#.|D|)"<<endl;
		cout<<"|O.O.O.O.O.#.#.#.#.#.#.|.|"<<endl;
		cout<<"|O.......................|"<<endl;
		cout<<"|O.O.O.O.O.#.#.#.#.#.#.|.|)"<<endl;
	}
	else if(n==17){
		
		cout<<"|O.O.O.O.O.O.#.#.#.#.#.|D|)"<<endl;
		cout<<"|O.O.O.O.O.#.#.#.#.#.#.|.|"<<endl;
		cout<<"|O.......................|"<<endl;
		cout<<"|O.O.O.O.O.#.#.#.#.#.#.|.|)"<<endl;
	}
	else if(n==18){
		
		cout<<"|O.O.O.O.O.O.#.#.#.#.#.|D|)"<<endl;
		cout<<"|O.O.O.O.O.O.#.#.#.#.#.|.|"<<endl;
		cout<<"|O.......................|"<<endl;
		cout<<"|O.O.O.O.O.#.#.#.#.#.#.|.|)"<<endl;
	}
	else if(n==19){
		
		cout<<"|O.O.O.O.O.O.#.#.#.#.#.|D|)"<<endl;
		cout<<"|O.O.O.O.O.O.#.#.#.#.#.|.|"<<endl;
		cout<<"|O.......................|"<<endl;
		cout<<"|O.O.O.O.O.O.#.#.#.#.#.|.|)"<<endl;
	}
	else if(n==20){
		
		cout<<"|O.O.O.O.O.O.O.#.#.#.#.|D|)"<<endl;
		cout<<"|O.O.O.O.O.O.#.#.#.#.#.|.|"<<endl;
		cout<<"|O.......................|"<<endl;
		cout<<"|O.O.O.O.O.O.#.#.#.#.#.|.|)"<<endl;
	}
	else if(n==21){
		
		cout<<"|O.O.O.O.O.O.O.#.#.#.#.|D|)"<<endl;
		cout<<"|O.O.O.O.O.O.O.#.#.#.#.|.|"<<endl;
		cout<<"|O.......................|"<<endl;
		cout<<"|O.O.O.O.O.O.#.#.#.#.#.|.|)"<<endl;
	}
	else if(n==22){
		
		cout<<"|O.O.O.O.O.O.O.#.#.#.#.|D|)"<<endl;
		cout<<"|O.O.O.O.O.O.O.#.#.#.#.|.|"<<endl;
		cout<<"|O.......................|"<<endl;
		cout<<"|O.O.O.O.O.O.O.#.#.#.#.|.|)"<<endl;
	}
	else if(n==23){
		
		cout<<"|O.O.O.O.O.O.O.O.#.#.#.|D|)"<<endl;
		cout<<"|O.O.O.O.O.O.O.#.#.#.#.|.|"<<endl;
		cout<<"|O.......................|"<<endl;
		cout<<"|O.O.O.O.O.O.O.#.#.#.#.|.|)"<<endl;
	}
	else if(n==24){
		
		cout<<"|O.O.O.O.O.O.O.O.#.#.#.|D|)"<<endl;
		cout<<"|O.O.O.O.O.O.O.O.#.#.#.|.|"<<endl;
		cout<<"|O.......................|"<<endl;
		cout<<"|O.O.O.O.O.O.O.#.#.#.#.|.|)"<<endl;
	}
	else if(n==25){
		
		cout<<"|O.O.O.O.O.O.O.O.#.#.#.|D|)"<<endl;
		cout<<"|O.O.O.O.O.O.O.O.#.#.#.|.|"<<endl;
		cout<<"|O.......................|"<<endl;
		cout<<"|O.O.O.O.O.O.O.O.#.#.#.|.|)"<<endl;
	}
	else if(n==26){
		
		cout<<"|O.O.O.O.O.O.O.O.O.#.#.|D|)"<<endl;
		cout<<"|O.O.O.O.O.O.O.O.#.#.#.|.|"<<endl;
		cout<<"|O.......................|"<<endl;
		cout<<"|O.O.O.O.O.O.O.O.#.#.#.|.|)"<<endl;
	}
	else if(n==27){
		
		cout<<"|O.O.O.O.O.O.O.O.O.#.#.|D|)"<<endl;
		cout<<"|O.O.O.O.O.O.O.O.O.#.#.|.|"<<endl;
		cout<<"|O.......................|"<<endl;
		cout<<"|O.O.O.O.O.O.O.O.#.#.#.|.|)"<<endl;
	}
	else if(n==28){
		
		cout<<"|O.O.O.O.O.O.O.O.O.#.#.|D|)"<<endl;
		cout<<"|O.O.O.O.O.O.O.O.O.#.#.|.|"<<endl;
		cout<<"|O.......................|"<<endl;
		cout<<"|O.O.O.O.O.O.O.O.O.#.#.|.|)"<<endl;
	}
	else if(n==29){
		
		cout<<"|O.O.O.O.O.O.O.O.O.O.#.|D|)"<<endl;
		cout<<"|O.O.O.O.O.O.O.O.O.#.#.|.|"<<endl;
		cout<<"|O.......................|"<<endl;
		cout<<"|O.O.O.O.O.O.O.O.O.#.#.|.|)"<<endl;
	}
	else if(n==30){
		
		cout<<"|O.O.O.O.O.O.O.O.O.O.#.|D|)"<<endl;
		cout<<"|O.O.O.O.O.O.O.O.O.O.#.|.|"<<endl;
		cout<<"|O.......................|"<<endl;
		cout<<"|O.O.O.O.O.O.O.O.O.#.#.|.|)"<<endl;
	}
	else if(n==31){
		cout<<"|O.O.O.O.O.O.O.O.O.O.#.|D|)"<<endl;
		cout<<"|O.O.O.O.O.O.O.O.O.O.#.|.|"<<endl;
		cout<<"|O.......................|"<<endl;
		cout<<"|O.O.O.O.O.O.O.O.O.O.#.|.|)"<<endl;
	}
	else if(n==32){
		cout<<"|O.O.O.O.O.O.O.O.O.O.O.|D|)"<<endl;
		cout<<"|O.O.O.O.O.O.O.O.O.O.#.|.|"<<endl;
		cout<<"|O.......................|"<<endl;
		cout<<"|O.O.O.O.O.O.O.O.O.O.#.|.|)"<<endl;
	}
	else if(n==33){
		cout<<"|O.O.O.O.O.O.O.O.O.O.O.|D|)"<<endl;
		cout<<"|O.O.O.O.O.O.O.O.O.O.O.|.|"<<endl;
		cout<<"|O.......................|"<<endl;
		cout<<"|O.O.O.O.O.O.O.O.O.O.#.|.|)"<<endl;
	}
	else if(n==34){
		cout<<"|O.O.O.O.O.O.O.O.O.O.O.|D|)"<<endl;
		cout<<"|O.O.O.O.O.O.O.O.O.O.O.|.|"<<endl;
		cout<<"|O.......................|"<<endl;
		cout<<"|O.O.O.O.O.O.O.O.O.O.O.|.|)"<<endl;
	}
	cout<<"+------------------------+"<<endl;
	return 0;
}