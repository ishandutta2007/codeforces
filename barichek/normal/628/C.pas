uses math;
var
  maxdist:array[1..100000]of longint;
  s,ans:ansistring;
  k,sum:longint;
  i:longint;
begin
  readln(k,k);
  read(s);

  for i:=1 to length(s) do
    begin
      maxdist[i]:=max(ord(s[i])-ord('a'),ord('z')-ord(s[i]));
      inc(sum,maxdist[i]);
    end;

  if sum<k then begin writeln(-1); halt; end;

  for i:=1 to length(s) do
    if k>0 then
      begin
        if ord(s[i])-ord('a')=maxdist[i] then
          if k>=maxdist[i] then ans:=ans+'a'
          else ans:=ans+chr(ord(s[i])-k)
        else
          if k>=maxdist[i] then ans:=ans+'z'
          else ans:=ans+chr(ord(s[i])+k);
        dec(k,abs(ord(s[i])-ord(ans[i])));
      end
    else ans:=ans+s[i];


  writeln(ans)
end.