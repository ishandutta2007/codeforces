var a:array[1..100]of longint;
    i,n,max,min,mii,mai:longint;
begin
 readln(n);max:=0;min:=999;
 for i:=1 to n do
 begin
  read(a[i]);
  if a[i]>max then begin max:=a[i];mai:=i;end;
  if a[i]<=min then begin min:=a[i];mii:=i;end;
 end;
 if mai>mii then
 begin
  writeln(mai-1+n-mii-1);
 end else
 begin
  writeln(mai-1+n-mii);
 end;
end.