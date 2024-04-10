var
 a:array[0..100] of longint;
 b,c,d,n,j,i:longint;
begin
 readln(n);
 for i:=1 to n do
 begin
  read(c);
  inc(a[c]);
 end;
 for i:=0 to 100 do
 for j:=1 to a[i] do writeln(i);
 readln;
end.