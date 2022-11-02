
 #include <bits/stdc++.h>
#define MAXN 105

using namespace std;
using namespace std::chrono;

int main () {
	milliseconds ms = duration_cast< milliseconds >(
    	system_clock::now().time_since_epoch()
	);
	uint64_t s = ms.count();
	int num = s % 2;
	if (num == 0) printf("even\n");
	else printf("odd\n");
	return 0;
}