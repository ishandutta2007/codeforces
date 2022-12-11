var a:array[1..250]of longint;
    i,n,m:longint;
begin
 readln(n,m);
 n:=2*n+1;
 for i:=1 to n do
  read(a[i]);
 for i:=1 to n do
 begin
  if i mod 2=0 then if (a[i]>a[i-1]+1)and(a[i]>a[i+1]+1)and(m>0) then begin a[i]:=a[i]-1;dec(m);end;
  write(a[i]);
  if i<n then write(' ');
 end;
end.