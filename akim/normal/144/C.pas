var s,t:ansistring;
    x,z:array['a'..'z']of longint;
    c:char;
    i,otv,kol,isp:longint;
    log:boolean;
procedure ins(y:char);
var c:char;begin if y='?' then begin inc(kol);for c:='a' to 'z' do inc(x[c]);end else inc(x[y]);end;
procedure del(y:char);
var c:char;begin if y='?' then begin dec(kol);for c:='a' to 'z' do dec(x[c]);end else dec(x[y]);end;
begin
 for c:='a' to 'z' do
 begin x[c]:=0;z[c]:=0;end;otv:=0;kol:=0;isp:=0;
 readln(s);
 readln(t);
 if length(t)>length(s) then begin writeln('0');halt(0);end;
 for i:=1 to length(t) do
  inc(z[t[i]]);
 for i:=1 to length(t) do
  ins(s[i]);
 log:=true;
 isp:=0;
 for c:='a' to 'z' do if x[c]<z[c] then begin log:=false;break;end else if x[c]-kol<z[c] then isp:=isp-x[c]+kol+z[c];
 if (log)and(isp<=kol) then inc(otv);
 for i:=length(t)+1 to length(s) do
 begin
  ins(s[i]);
  del(s[i-length(t)]);
  log:=true;
  isp:=0;
  for c:='a' to 'z' do if x[c]<z[c] then begin log:=false;break;end else if x[c]-kol<z[c] then isp:=isp-x[c]+kol+z[c];
  if (log)and(isp<=kol) then inc(otv);
 end;
 writeln(otv);
end.