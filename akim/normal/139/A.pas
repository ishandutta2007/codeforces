var a:array[0..6]of longint;
    n,i:longint;
begin
 readln(n);
 for i:=0 to 6 do
  read(a[i]);
 i:=0;
 while n>0 do
 begin
  n:=n-a[i];
  inc(i);
  i:=i mod 7;
 end;
 i:=i-1;
 if i=-1 then i:=6;
 writeln(i+1);
end.