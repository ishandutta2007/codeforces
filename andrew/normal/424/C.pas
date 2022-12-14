var
 p,d,f:array[0..1000000]of longint;
 q,i,j,ch1,n:longint;
begin
 readln(n);

 f[0]:=0;
 for i:=1 to n do f[i]:=f[i-1] xor i;
 q:=1;

 for i:=1 to n do
 begin
  read(p[i]);
  d[i]:=p[i] xor f[n mod i];
  if odd(n div i) then d[i]:=d[i] xor f[i-1];
 end;
 q:=d[1];
 for i:=2 to n do q:=q xor d[i];
 writeln(q);
end.