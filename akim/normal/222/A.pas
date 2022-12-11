var a:array[0..100000]of longint;
    n,k,i:longint;
begin
 readln(n,k);
 for i:=1 to n do
  read(a[i]);
 for i:=k+1 to n do
  if a[i]<>a[k] then begin writeln('-1');halt(0);end;
 i:=k;
 while a[i-1]=a[k] do dec(i);
 writeln(i-1);
end.