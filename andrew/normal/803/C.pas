var
 a,b:array[1..1000000]of int64;
 mx,sc,ch,NK,m,k,l,n,r:int64;
 i,j,ii:longint;
begin
 readln(n,k);
 if k>1000000 then begin writeln(-1); halt; end;
 mx:=-maxlongint;
 for i:=1 to n do
 begin
  if i>k then break;
  sc:=sc+i;
  if (sc>n) then begin writeln(-1); halt; end;
 end;

 for i:=1 to trunc(sqrt(n)) do if n mod i=0 then
 begin
  sc:=0;
  for j:=1 to k do begin a[j]:=i*j; sc:=sc+a[j]; end;
  if sc>n then continue;
  NK:=n-sc;
  if NK mod i=0 then
  begin
   a[k]:=a[k]+NK;
   if i>mx then
   begin
    mx:=i;
    for j:=1 to k do b[j]:=a[j];
   end;
  end;
 ii:=n div i;

   sc:=0;
  for j:=1 to k do begin a[j]:=ii*j; sc:=sc+a[j]; end;
  if sc>n then continue;
  NK:=n-sc;
  if NK mod ii=0 then
  begin
   a[k]:=a[k]+NK;
   if ii>mx then
   begin
    mx:=ii;
    for j:=1 to k do b[j]:=a[j];
   end;
  end;
 end;
 if mx=-maxlongint then begin writeln(-1); halt; end;
 for i:=1 to k do write(b[i],' ');
end.