var a:array[0..100100]of longint;
    n,i:longint;s,ipr:int64;
begin
 readln(n);a[0]:=0;
 for i:=1 to n do
  read(a[i]);ipr:=0;s:=0;
 for i:=1 to n do
  if a[i]<a[i-1] then
  begin
   if a[i]+ipr>=a[i-1] then begin ipr:=a[i-1]-a[i];a[i]:=a[i-1];end else
   begin s:=s+a[i-1]-ipr-a[i];ipr:=a[i-1]-a[i];a[i]:=a[i-1];end;
  end else ipr:=0;
 writeln(s);
end.