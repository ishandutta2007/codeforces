#include <iostream>
#include <string>

std::string s1,s2;

int main() {
	std::cin >> s1 >> s2;
	int n;
	scanf("%d",&n);
	std::cout << s1 << " " << s2<<std::endl;
	for(int i=0;i<n;i++) {
		std::string t1, t2;
		std::cin >> t1 >> t2;
		if(t1==s1)
			s1=t2;
		else
			s2=t2;

		std::cout << s1 << " " << s2 <<std::endl;
	}

	return 0;
}