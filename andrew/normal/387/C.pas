var
 v1,v2,s:ansistring;
 b,ch1,ch2,ch3,i,j,k,l,sc,o:longint;
begin
 sc:=1;
 readln(s);
 for i:=length(s) downto 2 do
 begin
  if (b=0)and(s[i]='0')then begin b:=i; continue; end;
  if (s[i]='0')then continue;
  if (b<>0)then v2:=copy(s,i,b-i+1) else v2:=s[i];
  v1:=copy(s,1,i-1);
  if length(v2)<length(v1)then begin b:=0;inc(sc); end
  else if length(v2)>length(v1)then break
  else if (length(v2)=length(v1))and(v1>=v2)then begin b:=0;inc(sc); end;
 end;
 writeln(sc);
end.