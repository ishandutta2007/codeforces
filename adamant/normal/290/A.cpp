#include<cstdio>

char s[40][99]={"Washington","Adams","Jefferson","Madison","Monroe","Adams","Jackson","Van Buren","Harrison","Tyler","Polk","Taylor","Fillmore","Pierce","Buchanan","Lincoln","Johnson","Grant","Hayes","Garfield","Arthur","Cleveland","Harrison","Cleveland","McKinley","Roosevelt","Taft","Wilson","Harding","Coolidge","Hoover","Roosevelt","Truman","Eisenhower","Kennedy","Johnson","Nixon","Ford","Carter","Reagan"};

main()
{
	int n;
	scanf("%d",&n);
	puts(s[n-1]);
}