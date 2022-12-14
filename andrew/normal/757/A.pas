var
 s:ansistring;
 a:array[1..255]of longint;
 sc,i,j,k,l,o,p:longint;
begin
 readln(s);
 for i:=1 to length(s) do inc(a[ord(s[i])]);

 while true do
 begin
  if (a[ord('B')]<1)or(a[ord('u')]<2)or(a[ord('l')]<1)or
   (a[ord('b')]<1)or(a[ord('a')]<2)or(a[ord('s')]<1)or(a[ord('r')]<1)then break;
  inc(sc);
  dec(a[ord('B')]);
  dec(a[ord('u')],2);
  dec(a[ord('l')]);
  dec(a[ord('b')]);
  dec(a[ord('a')],2);
  dec(a[ord('s')]);
  dec(a[ord('r')]);

 end;

 writeln(sc);
end.