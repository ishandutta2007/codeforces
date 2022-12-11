var a:array[1..2005]of longint;
    b,c,d,i,f,g:longint;
begin
 readln(b,c,d);
 for i:=1 to b do
  read(a[i]);
 for i:=1 to b-1 do
  for f:=i+1 to b do
   if a[i]<a[f] then begin g:=a[i];a[i]:=a[f];a[f]:=g;end;
 writeln(a[c]-a[c+1]);
end.