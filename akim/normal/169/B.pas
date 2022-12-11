{$H+}
var a:array[49..57]of longint;
    l,m,i,f:longint;
    b,j:ansistring;
begin
 readln(b);
 readln(j);
 l:=length(b);
 m:=length(j);
 for i:=1 to m do
  case j[i] of
   '1':inc(a[49]);
   '2':inc(a[50]);
   '3':inc(a[51]);
   '4':inc(a[52]);
   '5':inc(a[53]);
   '6':inc(a[54]);
   '7':inc(a[55]);
   '8':inc(a[56]);
   '9':inc(a[57]);
  end;
 m:=57;
 for f:=1 to l do
 begin
  while (m>0)and(a[m]=0) do dec(m);
  if m=0 then break;
  if ord(b[f])<m then begin b[f]:=chr(m);dec(a[m]);end;
 end;
 write(b);
end.