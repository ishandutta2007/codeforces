var a,b,c,d,i,j,k,l,m,n,rst,x,y:longint; s,way,s1:string; Z:array['A'..'Z'] of byte; ch:char;
T:array[0..3,0..14] of char;



Procedure PrintArray;
var i,j:longint;
begin
for i:=1 to 2 do begin for j:=1 to 13 do write(T[i,j]); writeln; end; writeln;
end;


begin
//assign(input,'d:\input.txt'); reset(input);
//assign(output,'d:\output.txt'); rewrite(output);
readln(way); s:=way;
for i:=1 to 27 do
if Z[s[i]]<>0 then begin rst:=i-Z[s[i]]-1;ch:=s[i]; break;
end else Z[s[i]]:=i;

if rst=0 then begin write('Impossible'); exit; end;

if rst mod 2=0 then
 begin
 a:=rst div 2; b:=Z[ch]+1;
 T[1,13-a]:=ch;
 for i:=13-a+1 to 13 do begin T[1,i]:=s[b]; inc(b); end;
 for i:=13 downto 13-a+1 do begin T[2,i]:=s[b]; inc(b); end;
 s1:=copy(s,1,Z[ch]-1); delete(s,1,Z[ch]+rst); s:=s+s1;
 x:=13-a; y:=2; c:=length(s);
 while c>0 do
  begin
  T[y,x]:=s[c]; c:=c-1;
  if y=1 then inc(x);
  if y=2 then dec(x); if x=0 then begin y:=1; x:=1; end;
  end;
 end;

if rst mod 2=1 then
 begin
 a:=rst div 2; b:=Z[ch]+1;
 T[1,13-a]:=ch;
 for i:=13-a+1 to 13 do begin T[1,i]:=s[b]; inc(b); end;
 for i:=13 downto 13-a do begin T[2,i]:=s[b]; inc(b); end;
 s1:=copy(s,1,Z[ch]-1); delete(s,1,Z[ch]+rst); s:=s+s1;
 x:=13-a-1; y:=2; c:=length(s);
 while c>0 do
  begin
  T[y,x]:=s[c]; c:=c-1;
  if y=1 then inc(x);
  if y=2 then dec(x); if x=0 then begin y:=1; x:=1; end;
  end;
 end;

PrintArray;
end.