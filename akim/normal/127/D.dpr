var a:array[-10..1001000]of longint;
    s:ansistring;
    i,f,l,p,max:longint;
function min(x,y:longint):longint;
begin min:=x; if y<x then min:=y;end;
begin
 readln(s);l:=length(s);
 a[1]:=0;f:=1;
 for i:=2 to l do
 begin
  if i<=f+a[f] then a[i]:=min(f+a[f]-i,a[i-f+1]);
  while (i+a[i]<=l)and(s[i+a[i]]=s[a[i]+1]) do inc(a[i]);
  if a[f]+f<a[i]+i then f:=i;
 end;
 max:=0;
 for i:=1 to l do
  if (max<a[i]) then begin max:=a[i];p:=i;end;
 for i:=1 to l do
  if (max>=a[i])and(i+a[i]-1=l)and(i<>p) then begin writeln(copy(s,1,a[i]));halt(0);end;
 writeln('Just a legend');
end.