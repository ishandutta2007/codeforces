var a:array[1..6000]of longint;
    n,m,i,s:longint;
begin
 readln(n);s:=0;
 for i:=1 to n do
 begin
  read(m);
  inc(a[m]);
  if m>n then inc(s);
 end;
 for i:=1 to n do
  if a[i]>1 then s:=s+a[i]-1;
 writeln(s);
end.