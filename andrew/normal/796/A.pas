var
 a:array[0..100000]of longint;
 ch1,ch2,ch3,sc,k,m:longint;
 n,i,j:longint;
procedure odd(x:longint);
begin
 if(x<1)or(x>n)or(a[x]=0)then exit;
 if a[x]<=k then begin writeln(i*10); halt; end;
end;
begin
 readln(n,m,k);
 for i:=1 to n do read(a[i]);
 for i:=1 to n do
 begin
  odd(m-i);
  odd(m+i);
 end;
end.