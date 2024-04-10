var s,h,m:string;
    max:longint;
    log:array[0..65]of boolean;
    h1,m1,i,f,k:longint;
function num(c:char):longint;begin case c of '0':num:=00; '1':num:=01; '2':num:=02; '3':num:=03; '4':num:=04; '5':num:=05; '6':num:=06; '7':num:=07; '8':num:=08; '9':num:=09; 'A':num:=10; 'B':num:=11; 'C':num:=12; 'D':num:=13; 'E':num:=14; 'F':num:=15; 'G':num:=16; 'H':num:=17; 'I':num:=18; 'J':num:=19; 'K':num:=20; 'L':num:=21; 'M':num:=22; 'N':num:=23; 'O':num:=24; 'P':num:=25; 'Q':num:=26; 'R':num:=27; 'S':num:=28; 'T':num:=29; 'U':num:=30; 'V':num:=31; 'W':num:=32; 'X':num:=33; 'Y':num:=34; 'Z':num:=35; end;end;
begin
 readln(s);max:=0;
 for i:=1 to length(s) do
  if s[i]<>':' then begin if max<num(s[i]) then max:=num(s[i]);end else begin h:=copy(s,1,i-1);m:=copy(s,i+1,length(s)-i);end;
 inc(max);
 k:=1;h1:=0;
 for f:=length(h) downto 1 do
 begin
  h1:=h1+k*num(h[f]);
  k:=k*max;
 end;
 k:=1;m1:=0;
 for f:=length(m) downto 1 do
 begin
  m1:=m1+k*num(m[f]);
  k:=k*max;
 end;
 if (h1<=23)and(m1<=59) then log[max]:=true else begin writeln('0');halt(0);end;
 for i:=max+1 to 60 do
 begin
  k:=1;h1:=0;
  for f:=length(h) downto 1 do
  begin
   h1:=h1+k*num(h[f]);
   k:=k*i;
  end;
  k:=1;m1:=0;
  for f:=length(m) downto 1 do
  begin
   m1:=m1+k*num(m[f]);
   k:=k*i;
  end;
  if (h1<=23)and(m1<=59) then log[i]:=true;
  if not(log[i]) then break;
 end;
 if log[60]=true then begin writeln('-1');halt(0);end;
 for i:=max to 60 do
  if log[i] then write(i,' ');
end.