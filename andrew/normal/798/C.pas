var
 a:array[1..100001]of longint;
 gc,ans,sc,i,j,n,m,k,kol:longint;
function GCD(a,b:longint):longint;
begin
 while(a<>0)and(b<>0)do if a>b then a:=a mod b else b:=b mod a;
 GCD:=a+b;
end;
begin
 readln(n);
 for i:=1 to n do read(a[i]);
 sc:=0;
 writeln('YES');
 gc:=a[1];
 for i:=2 to n do gc:=gcd(gc,a[i]);
 if gc>1 then begin writeln(0); halt; end;
 for i:=1 to n do a[i]:=a[i] mod 2;
 ans:=0;
 for i:=1 to n+1 do
 begin
  if a[i]=1 then begin inc(k); continue; end;
  ans:=ans+trunc(k/2+k mod 2*2);
  k:=0;
 end;
 writeln(ans);
end.