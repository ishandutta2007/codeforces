var s:ansistring;
    c:char;
    i,l,kc:longint;
begin
 readln(s);l:=length(s);c:='a';kc:=0;
 for i:=1 to l do
 begin
  if s[i]>c then begin c:=s[i];kc:=0;end;
  if s[i]=c then inc(kc);
 end;
 for i:=1 to kc do
  write(c);
end.