var
 c,b,x,i,j,n:Longint;
 a:array[1..100]of longint;
function gcd(a,b:longint):longint;
begin
 while(a<>0)and(b<>0)do if a>b then a:=a mod b else b:=b mod a;
 gcd:=a+b;
end;
begin
 readln(n);
 for i:=1 to n do read(a[i]);
 c:=a[1];
 for i:=1 to n do c:=gcd(c,a[i]);
 writeln(c*n);
end.