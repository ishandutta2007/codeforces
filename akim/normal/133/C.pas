var s:string;pred,tek,c,i,l:longint;
begin
 pred:=0;tek:=0;
 readln(s);l:=length(s);
 for i:=1 to l do
 begin
  pred:=tek;tek:=0;
  c:=ord(s[i]);
  if c>=128 then begin c:=c-128;tek:=tek+1;end;
  if c>=64 then begin c:=c-64;tek:=tek+2;end;
  if c>=32 then begin c:=c-32;tek:=tek+4;end;
  if c>=16 then begin c:=c-16;tek:=tek+8;end;
  if c>=8 then begin c:=c-8;tek:=tek+16;end;
  if c>=4 then begin c:=c-4;tek:=tek+32;end;
  if c>=2 then begin c:=c-2;tek:=tek+64;end;
  if c>=1 then begin c:=c-1;tek:=tek+128;end;
  if pred-tek>=0 then writeln((pred-tek)) else writeln((pred-tek)+256);
 end;
end.